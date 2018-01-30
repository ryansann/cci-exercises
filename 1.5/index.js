// Check if strings are one edit away from one another
// return true if they are one edit away, otherwise return false
// order matters here
// Check:
// - replace
// - insert
// - remove

// O(n) time
// O(n) space
function checkEdits(str1, str2) {
  // more than one character length difference implies > 1 edit away
  if (str1.length == str2.length) {
    return checkReplace(str1, str2);
  } else if (str1.length - str2.length === 1) { // str1 longer by one char
    return checkInsert(str1, str2);
  } else if (str2.length - str1.length === 1) { // str2 longer by one char
    return checkInsert(str2, str1);
  } else {
    return false;
  }
}

// helper
function checkReplace(str1, str2) {
  let foundDifference = false;
  for (let idx in str1) {
    if (str1[idx] !== str2[idx]) {
      if (foundDifference) {
        return false;
      } else {
        foundDifference = true;
      }
    }
  }
  return true;
}

// helper
function checkInsert(str1, str2) { // str1 is longer by one char
  let idx1 = 0, idx2 = 0, foundMissing = false;
  while (idx1 < str1.length && idx2 < str2.length) {
    if (str1[idx1] === str2[idx2]) {
      idx1++;
      idx2++;
    } else {
      if (foundMissing) { // we already found a missing char & can't have > 1
        return false;
      } else {
        foundMissing = true;
        idx1++;
      }
    }
  }
  return true;
}

// Tests
console.log("Check true:");
console.log(`checkEdits('', ''): ${checkEdits('', '')}`);
console.log(`checkEdits('', 'a'): ${checkEdits('', 'a')}`);
console.log(`checkEdits('pale', 'ple'): ${checkEdits('pale', 'ple')}`);
console.log(`checkEdits('pales', 'pale'): ${checkEdits('pales', 'pale')}`);
console.log(`checkEdits('pale', 'bale'): ${checkEdits('pale', 'bale')}`);
console.log("Check false:");
console.log(`checkEdits('pale', 'bake'): ${checkEdits('pale', 'bake')}`);
console.log(`checkEdits('paleeee', 'bake'): ${checkEdits('paleeee', 'bake')}`);
console.log(`checkEdits('pale', 'elap'): ${checkEdits('pale', 'elap')}`);

// Improvements:
// - make more modular
// - break into separate cases for each edit operation