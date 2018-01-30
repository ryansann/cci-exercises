// Check if a string is a permutatino of a palindrome

// build hash map of word and check hash map for palindrome criteria
// - O(n) time (this is best case since we always have to iterate throught the entire string)
// - O(n) space
function checkPalindrome(str) {
  if (str.length === 0 || str.length === 1) return true;
  let charMap = {};
  for (let char of str) {
    if (charMap[char]) {
      charMap[char]++;
    } else {
      charMap[char] = 1;
    }
  }
  let foundOdd = false;
  for (let char in charMap) {
    if (charMap[char] % 2 === 1) {
      if (foundOdd) {
        return false;
      } else {
        foundOdd = true;
      }
    }
  }
  return true;
}

// tests
console.log('Check true:');
console.log(`checkPalindrome("hiigh"): ${checkPalindrome("hiigh")}`); // true
console.log(`checkPalindrome("racecar"): ${checkPalindrome("racecar")}`); // true
console.log(`checkPalindrome("LttL"): ${checkPalindrome("LttL")}`); // true
console.log('\nCheck false: ');
console.log(`checkPalindrome("nope"): ${checkPalindrome("nope")}`); // false
console.log(`checkPalindrome("lttL"): ${checkPalindrome("lttL")}`); // false
console.log(`checkPalindrome("hiigh "): ${checkPalindrome("hiigh ")}`); // false