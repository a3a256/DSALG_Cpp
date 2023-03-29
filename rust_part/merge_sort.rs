use std::convert::TryInto;


fn combine(left: Vec<i32>, right: Vec<i32>)->Vec<i32>{
    let mut i: i32 = 0;
    let mut d: i32 = 0;
    let mut i_index: usize;
    let mut j_index: usize;
    let leftln: i32 = (left.len()).try_into().unwrap();
    let rightln: i32 = (right.len()).try_into().unwrap();
    let mut res: Vec<i32> = Vec::new();
    while i<leftln && d<rightln{
        i_index = (i).try_into().unwrap();
        j_index = (d).try_into().unwrap();
        if left[i_index] < right[j_index]{
            res.push(left[i_index]);
            i += 1;
        }else{
            res.push(right[j_index]);
            d += 1;
        }
    }

    while i<leftln{
        i_index = (i).try_into().unwrap();
        res.push(left[i_index]);
        i += 1;
    }

    while d<rightln{
        j_index = (d).try_into().unwrap();
        res.push(right[j_index]);
        d += 1;
    }


    return res;
}



fn merge_sort(arr: Vec<i32>)->Vec<i32>{
    let length: i32 = (arr.len()).try_into().unwrap();
    if length == 1{
        return arr;
    }

    let middle: i32 = length/2;

    let mut left: Vec<i32> = Vec::new();
    let mut right: Vec<i32> = Vec::new();
    let mut i = 0;
    let mut i_index: usize;
    let mut j_index: usize;
    while i<middle{
        i_index = (i).try_into().unwrap();
        left.push(arr[i_index]);
        i += 1;
    }

    while i<length{
        j_index = (i).try_into().unwrap();
        right.push(arr[j_index]);
        i += 1;
    }


    return combine(merge_sort(left), merge_sort(right));
}


fn main(){
    let vec: Vec<i32> = vec![2, 1, 4, 13, 11, 9];

    let res: Vec<i32> = merge_sort(vec);

    let mut i: i32 = 0;

    let length: i32 = (res.len()).try_into().unwrap();

    let mut index: usize;

    while i<length{
        index = (i).try_into().unwrap();
        println!("{}", res[index]);
        i += 1
    }

    // println!("{}", res[0 as usize]);
}