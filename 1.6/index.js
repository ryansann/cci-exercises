// Compress and decompress strings

// O(n) time
// ? space -> string copying
function compress(str) {
  let compressedStr = "", charCount = 1, idx = 0;
  while(idx < str.length) {
    let c = str[idx];
    if (idx + 1 > str.length) { // no look ahead
      compressedStr = `${compressedStr}${c}${charCount.toString()}`;
    } else { // look ahead available (not at end of string yet)
      if (c !== str[idx + 1]) {
        compressedStr = `${compressedStr}${c}${charCount.toString()}`;
        charCount = 1;
      } else {
        charCount++
      }
    }
    idx++;
  }
  if (str.length < compressedStr.length) {
    return str;
  } else {
    return compressedStr;
  }
}

// Tests
console.log("Check:");
console.log(`compress('aaabbb'): ${compress('aaabbb')} == a3b3`);
console.log(`compress('ab'): ${compress('ab')} == ab`);
console.log(`compress('aabcccccaaa'): ${compress('aabcccccaaa')} == a2b1c5a3`);
