import QtQuick 2.15
import QtQuick.Controls 2.15 as Controls
import QtQuick.Layouts 1.15
import org.kde.kirigami 2.20 as Kirigami

Kirigami.ApplicationWindow {
  id: root

  minimumWidth: 200
  minimumHeight: minimumWidth

  width: 200
  height: width

  title: "Tapper"

  Shortcut {
    sequence: "space"
    onActivated: tapButton.clicked()
  }

  pageStack.initialPage: Kirigami.Page {
    id: page

    title: tapper.bpm

    actions {
      main: Kirigami.Action {
        text: "Reset"
        icon.name: "view-refresh-symbolic"

        onTriggered: tapper.reset()
      }
    }

    Controls.Button {
      id: tapButton

      text: "Tap"
      anchors.fill: parent

      onClicked: tapper.click()
    }
  }
}
