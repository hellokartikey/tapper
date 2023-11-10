#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QQuickStyle>
#include <QUrl>

#include "tapper.h"

auto main(int argc, char *argv[]) -> int {
  using qca = QCoreApplication;
  qca::setAttribute(Qt::AA_EnableHighDpiScaling);
  qca::setOrganizationName(QStringLiteral("hellokartikey"));
  qca::setOrganizationDomain(QStringLiteral("github.com/hellokartikey"));
  qca::setApplicationName(QStringLiteral("Tapper"));

  auto app = QApplication(argc, argv);

  auto engine = QQmlApplicationEngine();

  engine.rootContext()->setContextProperty("tapper", new Tapper);
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if (engine.rootObjects().isEmpty()) {
    return -1;
  }

  return app.exec();
}
