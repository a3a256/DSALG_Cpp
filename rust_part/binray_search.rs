use std::convert::TryInto;

fn iterative_search(vec: Vec<i32>, target: i32)->i32{
    let mut start: i32 = 0;
    let mut end: i32 = (vec.len()).try_into().unwrap();
    end -= 1;
    let mut _mid: i32 = 0;
    let mut mid: usize = 0;

    while start <= end{
        _mid = (start + end)/2;
        mid = (_mid).try_into().unwrap();
        if vec[mid] == target{
            return _mid;
        }else if vec[mid] < target{
            start = _mid + 1;
        }else if vec[mid] > target{
            end = _mid - 1;
        }
    }

    return _mid;
}

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

    println!("{}", binary_search(0 as i32, 6 as i32, vec.clone(), 13 as i32));

    println!("{}", iterative_search(vec.clone(), 13 as i32))
}