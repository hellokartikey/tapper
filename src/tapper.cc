#include "tapper.h"

Tapper::Tapper(QObject *parent) : QObject(parent) {}

uint Tapper::getBpm() const {
  return bpm;
}

void Tapper::setBpm(const uint& bpm) {
  if (this->bpm != bpm) {
    this->bpm = bpm;
    emit changedBpm();
  }
}

void Tapper::click() {
  if (clicks++ == 0) {
    start = hrc::now();
    return;
  }

  auto time = hrc::now() - start;

  double diff = std::chrono::duration_cast<ms>(time).count();

  if (diff) {
    double new_bpm = (clicks * 60) / (diff / 1000);
    setBpm(new_bpm);
  }
}

void Tapper::reset() {
  setBpm(0u);
}

#include "moc_tapper.cpp"
