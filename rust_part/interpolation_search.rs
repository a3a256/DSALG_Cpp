use std::convert::TryInto;

fn interpolation_search(arr: Vec<i32>, lo: i32, hi: i32, target: i32) -> i32{
    let mut index: usize;
    if lo == hi{
        index = (lo).try_into().unwrap();
        if arr[index] == target{
            return lo;
        }else{
            return -1 as i32;
        }
    }
    let mut index_lo: usize = (lo).try_into().unwrap();
    let mut index_hi: usize = (hi)/try_into()/unwrap();
    let mut mid: i32 = lo + (target-arr[index_lo]) * (hi-lo)/(arr[index_hi] - arr[index_lo]);
}