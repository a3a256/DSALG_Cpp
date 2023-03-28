use std::convert::TryInto;

fn interpolation_search(arr: Vec<i32>, lo: i32, hi: i32, target: i32) -> i32{
    let index: usize;
    if lo == hi{
        index = (lo).try_into().unwrap();
        if arr[index] == target{
            return lo;
        }else{
            return -1 as i32;
        }
    }
    let index_lo: usize = (lo).try_into().unwrap();
    let index_hi: usize = (hi).try_into().unwrap();
    let mid: i32 = lo + (target-arr[index_lo]) * (hi-lo)/(arr[index_hi] - arr[index_lo]);

    let mut _annot: usize = (mid).try_into().unwrap();

    if arr[_annot] == target{
        return mid;
    }else if arr[_annot] > target{
        return interpolation_search(arr, lo, mid-1, target);
    }else if arr[_annot] < target{
        return interpolation_search(arr, mid+1, hi, target);
    }

    return -1;
}


fn main(){
    let vec: Vec<i32> = vec![1, 4, 5, 7, 9, 13, 17];
    let end: i32 = (vec.len()).try_into().unwrap();
    println!("{}", interpolation_search(vec, 0 as i32, end-1, 9 as i32));
}