use std::convert::TryInto;


enum Option<T>{
    Some(T),
    None,
}


struct Node{
    value: Option<i32> = None;
    next: Node;

    fn Node(val: i32){
        value = Some(value);
    }
}