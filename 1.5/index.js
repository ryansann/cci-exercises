// Check if strings are one edit away from one another
// return true if they are one edit away, otherwise return false

// O(n) time
// O(n) space
function checkEdits(str1, str2) {
  // more than one character length difference implies > 1 edit away
  if (Math.abs(str1.length - str2.length) > 1) return false;

  // if more than one character is different then we are not one edit away
  // build charMap
  let charMap = {}
  for (let c of str1) {
    if (charMap[c]) {
      charMap[c]++;
    } else {
      charMap[c] = 1;
    }
  }
  
  // track number of edits
  let numEdits = 0;
  
  // update charMap with str2
  for (let c of str2) {
    if (charMap[c]) {
      charMap[c]--;
    }
  }

  // iterate charMap to count rest of edits
  for (let c in charMap) {
    numEdits += charMap[c];
  }

  if (numEdits > 1) {
    return false;
  } else {
    return true;
  }
}

// Tests
console.log("Check true:");
console.log(`checkEdits('pale', 'ple'): ${checkEdits('pale', 'ple')}`);
console.log(`checkEdits('pales', 'pale'): ${checkEdits('pales', 'pale')}`);
console.log(`checkEdits('pale', 'bale'): ${checkEdits('pale', 'bale')}`);
console.log("Check false:");
console.log(`checkEdits('pale', 'bake'): ${checkEdits('pale', 'bake')}`);
console.log(`checkEdits('paleeee', 'bake'): ${checkEdits('paleeee', 'bake')}`);


// Improvements:
// - make more modular
// - break into separate cases for each edit operation