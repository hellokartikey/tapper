#ifndef TAPPER_H
#define TAPPER_H

#include <chrono>

#include <QObject>

class Tapper : public QObject {
  Q_OBJECT

  Q_PROPERTY(
    uint bpm
    READ getBpm
    WRITE setBpm
    NOTIFY changedBpm
  )

  using ms = std::chrono::milliseconds;
  using hrc = std::chrono::high_resolution_clock;
  using time_point = std::chrono::time_point<std::chrono::high_resolution_clock>;
  using duration = std::chrono::duration<double>;

public:
  Tapper(QObject *parent = nullptr);

  uint getBpm() const;
  void setBpm(const uint& bpm);

  Q_INVOKABLE void click();
  Q_INVOKABLE void reset();

signals:
  void changedBpm();

private:
  uint bpm = 0u;

  uint clicks = 0u;

  time_point start;
};

#endif
