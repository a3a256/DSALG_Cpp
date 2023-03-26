fn binary_search(start: i32, end: i32, vec: Vec<i32>, target: i32)->i32{
//     let _mid: i32 = (start+end)/2;
//     let mid: usize = (start+end)/2;
//     if vec[mid] == target{
//         return _mid;
//     }else if vec[mid] > target{
//         return binary_search(start, _mid-1, vec, target);
//     }else if vec[mid] < target{
//         return binary_search(_mid+1, end, vec, target);
//     }

//     return -1;
// }