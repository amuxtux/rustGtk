rustGtk
=======

interfacing gtk from rust 

1. install gtk+

2. write your gui code. in my case its gui.c and gui.h

3. compile gui.c
gcc -c -fPIC gui.c -o gui.o `pkg-config --cflags --libs gtk+-2.0`

4. create a dynamil library
gcc -shared -Wl,-soname,libgui.so -o libgui.so  gui.o `pkg-config --cflags --libs gtk+-2.0`

5. write a rust wrapper which links to external mod gui and compile using rustc
rustc rust-gui.rs -L./

6. note:
you may have to set LD_LIBRARY_PATH so that gcc can locate you .so files


