// Check Permutations of two strings
// assumes case insensitivity
// lengths must be the same for one to be the permutation of the other
// must contain the same characters

// return true if one string is a permutation of the other
// more efficient implementation
// O(n*log(n)) time assuming O(n*log(n)) javascript sort
// O(n) space
function checkPermutation(str1, str2) {
  if (typeof str1 !== 'string' || typeof str2 !== 'string') { // at least one is not a string
    return false;
  } else if (str1.length !== str2.length) { // different lengths
    return false;
  } else if (str1 === str2) { // same strings
    return true;
  }
  str1Sorted = str1.split('').sort(sortComparator).join('');
  str2Sorted = str2.split('').sort(sortComparator).join('');
  if (str1Sorted === str2Sorted) {
    return true;
  } else {
    return false;
  }
}

sortComparator = (a, b) => {
  return (a > b) - (a < b);
}

console.log(`checkPermutation("a", "aa") = ${checkPermutation("a", "aa")}`);
console.log(`checkPermutation("mr", "rm") = ${checkPermutation("mr", "rm")}`);
console.log(`checkPermutation("hello", "lolhe") = ${checkPermutation("hello", "lolhe")}`);
console.log(`checkPermutation("hello", "hello") = ${checkPermutation("hello", "hello")}`);
console.log(`checkPermutation("HEllo", "hello") = ${checkPermutation("hello", "hello")}`);
