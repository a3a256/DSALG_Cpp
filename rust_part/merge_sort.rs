use std::convert::TryInto;



fn mergeSort(arr: Vec<i32>)->Vec<i32>{
    let length: i32 = (arr.len()).try_into().unwrap();
    if length == 1{
        return arr;
    }

    let middle: i32 = length/2;

    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();
    let mut i = 0;
    while i<middle{
        left.push(arr[i]);
        i += 1;
    }

    while i<length{
        right.push(arr[i]);
        i += 1;
    }
}