 #!/bin/sh
gcc -c -fPIC gui.c -o gui.o `pkg-config --cflags --libs gtk+-2.0`
gcc -shared -Wl,-soname,libgui.so -o libgui.so  gui.o `pkg-config --cflags --libs gtk+-2.0`
rustc rust-gui.rs -L ./