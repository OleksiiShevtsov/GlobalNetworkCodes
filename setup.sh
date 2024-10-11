BUILD_DIR="$1"
SRC_DIR="$2"
QT_DIR="$3"

cp "$QT_DIR/bin/Qt5Cored.dll" "$BUILD_DIR/Qt5Cored.dll"
cp "$QT_DIR/bin/Qt5Guid.dll" "$BUILD_DIR/Qt5Guid.dll"
cp "$QT_DIR/bin/Qt5Widgetsd.dll" "$BUILD_DIR/Qt5Widgetsd.dll"

mkdir -p "$BUILD_DIR/platforms"
cp "$QT_DIR/plugins/platforms/qwindowsd.dll" "$BUILD_DIR/platforms/qwindowsd.dll"

cp -f "$SRC_DIR/db/OM system.db" "$BUILD_DIR/OM system.db"
