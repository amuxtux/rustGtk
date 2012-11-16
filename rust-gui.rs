
use libc::{c_char, c_void, c_int, c_uint};
use os;
extern mod gui{
  fn showGtkUI(argc:c_int, argv:**c_char);
  fn giveMeACall(f: *fn());
}

 extern fn callback()-> () unsafe {
   io::println("this is call back executing from c heyyyyyy  ");
}


fn main() {

  //this code block it to test the callback from c
  // eventually i will use it to know when submit button is pressed in gtk gui.
  // TBD::  passing some argument in callback function.
  io::println(" ====== sending a callback function to C function giveMeACall =============");
  unsafe{
     let cb: *fn() = cast::reinterpret_cast(&callback) ;
     gui::giveMeACall(cb);
  }
  io::println("========== callback worked ==========");
  
      
  //showing gtk gui
  let args = os::args().map(|arg| str::as_c_str(*arg, |buf| buf));    
  unsafe {
        gui::showGtkUI(args.len() as c_int, vec::raw::to_ptr(args));
  }
  

}

