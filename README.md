# Die GHO-Äpp (inoffiziell)

[![Build Status](https://travis-ci.org/gamingh/ghoAepp.svg?branch=master)](https://travis-ci.org/gamingh/ghoAepp)
[![Release](https://img.shields.io/github/release/gamingh/ghoAepp.svg)](https://github.com/gamingh/ghoAepp/releases)


Die neue GHO-Äpp bietet dir unbegrenzte Möglichkeiten für dein Stundenplan-Management!
Sie kann dir immer sagen welche Stunden ausfallen und vertreten werden! Du brauchst nur
das "ghoschueler" Passwort und schon kann's losgehen! Ist das nicht total toll?

`// Screenshots gibts sobald die App auch was kann... //`

# How to build

#### Installiere die Abhängigkeiten:
 * [Qt](http://doc.qt.io/qt-5/build-sources.html) (Core Qml Quick QuickControls2) (>= 5.7.0)
 * [Kirigami 2](https://phabricator.kde.org/source/kirigami/) (>= 2.0.0)

#### Besorge dir den source code:

```bash
git clone https://github.com/gamingh/ghoAepp
```
#### Kompiliere das ganze:

```bash
mkdir ghoAepp/build ; cd ghoAepp/build
cmake .. -DCMAKE_BUILD_TYPE="Release"
make -j$(nproc)
```

#### Jetzt kannst du die GHO-Aepp starten:

```bash
./ghoaepp
```

#### Wenn du sie magst, installiere sie dir doch:

 ```bash
 sudo make install
 ```
