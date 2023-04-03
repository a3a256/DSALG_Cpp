use std::convert::TryInto;


enum Option<T>{
    Some(T),
    None,
}


struct Node{
    value: Option<i32> = None;
    next: Node;

    fn Node(val: i32){
        value = Some(val);
        next = Some(None);
    }
}


impl LinkedList for Node{
    fn add(&self, ent: i32){
        return;
    }
}