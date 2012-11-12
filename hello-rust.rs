//#[link_name = "hello"]

extern mod hello{
  fn hello();
}

fn main() {
    hello::hello();
}
