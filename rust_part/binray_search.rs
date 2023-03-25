use std::convert::TryInto;

fn binary_search(start: i32, end: i32, vec: Vec<i32>, target: i32)->i32{
    let _mid: i32 = (start+end)/2;
    let mid: usize = ((start+end)/2).try_into().unwrap();
    if vec[mid] == target{
        return _mid;
    }else if vec[mid] > target{
        return binary_search(start, _mid-1, vec, target);
    }else if vec[mid] < target{
        return binary_search(_mid+1, end, vec, target);
    }

    return -1;
}



fn main(){
    let vec: Vec<i32> = vec![1, 4, 5, 7, 9, 13, 17];
    // let vec = vec![1, 24, 3, 5, 2];
    let mut i = 0;
    while i<vec.len(){
        println!("{}", vec[i]);
        i += 1;
    }

    let u: i32 = 5;

    println!("{}", u/2);

    println!("{}", binary_search(0 as i32, 6 as i32, vec, 13 as i32));
}