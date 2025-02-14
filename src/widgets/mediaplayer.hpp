#ifndef MEDIAPLAYER_HPP
#define MEDIAPLAYER_HPP

#include <QtGlobal>
#include <QWidget>
#include <QBuffer>
#include <QVideoWidget>
#include <QMediaPlayer>

namespace Ui {
class MediaPlayer;
}

class MediaPlayer : public QWidget
{
    Q_OBJECT

public:
    explicit MediaPlayer(QWidget *parent = nullptr);
    ~MediaPlayer();

    void setMedia(QByteArray const & data, QUrl const & ref_url, QString const & mime);

    void stopPlaying();

private slots:
    void on_playpause_button_clicked();

    void on_mute_button_clicked(bool checked);

private: // slots
    void on_media_positionChanged(qint64 pos);

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    void on_media_playbackChanged(QMediaPlayer::State);
#else
    void on_media_playbackChanged(QMediaPlayer::PlaybackState);
#endif

private:
    Ui::MediaPlayer *ui;
    QBuffer media_stream;
    QString mime;
    QMediaPlayer player;
};

#endif // MEDIAPLAYER_HPP
