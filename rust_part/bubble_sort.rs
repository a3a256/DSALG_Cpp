use std::convert:TryInto;


fn bubble_sort(arr: &mut Vec<i32>)->Vec<i32>{
    let mut sorted: bool = false;
    let mut i: i32 = 0;
    let mut temp: i32;
    let length: i32 = (arr.len()).try_into().unwrap();
    let mut i_index: usize;
    let mut j_index: usize;
    while !(sorted){
        sorted = true;
        i = 0;
        while i<length-1{
            i_index = (i).try_into().unwrap();
            j_index = (i+1).try_into().unwrap();
            if arr[i_index] > arr[j_index]{
                sorted = false;
                temp = arr[i_index];
                arr[i_index] = arr[j_index];
                arr[j_index] = temp;
            }
            i += 1;
        }
    }


    return arr;
}