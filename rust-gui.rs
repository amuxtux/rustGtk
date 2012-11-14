
use libc::{c_char, c_void, c_int, c_uint};
use os;
extern mod gui{
  fn showGtkUI(argc:c_int, argv:**c_char);
  fn giveMeACall(f: *fn());
}

 fn callback()-> () {
   io::println("this is call back executing from c heyyyyyy  ");
}


fn main() {
  io::println("executing giveMeACall ");
  
/*
  unsafe{
     let cb: *fn() = ptr::addr_of(&callback);
     gui::giveMeACall(cb);
  }
*/

  io::println("seems executed ");
      
  let args = os::args().map(|arg| str::as_c_str(*arg, |buf| buf));
      
  unsafe {
        gui::showGtkUI(args.len() as c_int, vec::raw::to_ptr(args));
  }
  

}

