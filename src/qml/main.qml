
import org.kde.kirigami 2.0 as Kirigami
import QtQuick.Controls 2.0 as Controls

Kirigami.ApplicationWindow {
	id: root
	width: 960
	height: 540
	
	Controls.Button {
		visible: true
		text: "Test Download"
		onClicked: ghoApp.downloadJson();
	}
}


