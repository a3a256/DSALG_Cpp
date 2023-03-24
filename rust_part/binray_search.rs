fn binary_search(start: i32, end: i32, v: let mut& Vec<i32>, target: i32)->i32{
    let mid: i32 = (start+end)/2;
    if v[mid] == target{
        return mid;
    }else if v[mid] > target{
        return binary_search(start, mid-1, v, target);
    }else if v[mid] < target{
        return binary_search(mid+1, end, v, target);
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

    println!("{}", binary_search(0 as i32, 6 as i32, vec, 13 as i32));
}