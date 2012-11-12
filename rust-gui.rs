
use libc::{c_char, c_void, c_int, c_uint};
use os;
extern mod gui{
  fn showGtkUI(argc:c_int, argv:**c_char);
}

fn main() {
      let args = os::args().map(|arg| str::as_c_str(*arg, |buf| buf));

  unsafe {
    gui::showGtkUI(args.len() as c_int, vec::raw::to_ptr(args));
  }
}


