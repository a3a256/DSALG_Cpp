use std::convert::TryInto;


fn combine(left: Vec<i32>, right: Vec<i32>)->Vec<i32>{
    let mut i: i32 = 0;
    let mut j: i32 = 0;
    let leftln: i32 = (left.len()).try_into().unwrap();
    let rightln: i32 = (right.len()).try_into().unwrap();
    let mut res: Vec<i32> = Vec::new();
    while i<leftln && j<rightln{
        if left[i] < right[j]{
            res.push(left[i]);
            i += 1;
        }else{
            res.push(right[j]);
            j += 1;
        }
    }

    while i<leftln{
        res.push(left[i]);
        i += 1;
    }

    while j<rightln{
        res.push(right[j]);
        j += 1;
    }


    return res;
}



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