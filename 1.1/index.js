// This assumes the ASCII character set

// with additional data structures
// return true if string is comprised of only unique characters otherwise return false
// O(n) time
// O(n) space
function checkUnique(str) {
  if (typeof str !== "string") {
    return false;
  } else if (str.length > 128) {
    return false; // must be dupes if we have more than 128 characters 
  }
  charHash = {};
  for (char of str) {
    if (charHash[char]) {
      charHash[char]++;
      console.log(JSON.stringify(charHash));
      return false;
    } else {
      charHash[char] = 1;
    }
  }
  console.log(JSON.stringify(charHash));
  return true;
}

// without additional data structures
// return true if string is comprised of only unique characters otherwise return false
// O(n^2) time
// O(1) space
function checkUnique2(str) {
  if (typeof str !== "string") {
    return false;
  } else if (str.length > 128) {
    return false; // must be dupes if we have more than 128 characters 
  }
  for (i = 0; i < str.length; i++) {
    for(j = i + 1; j < str.length; j++) {
      if (str[i] === str[j]) {
        console.log(`'${str[i]}' == '${str[j]}'`);
        return false;
      }
    }
  }
  return true;
}

// tests
console.log(`Checking 'about': ${checkUnique("about")}`);
console.log(`Checking 'testing': ${checkUnique("testing")}`);
console.log(`Checking 'dub spc ': ${checkUnique("dub spc ")}`);

console.log(`Checking 'about': ${checkUnique2("about")}`);
console.log(`Checking 'bigger string': ${checkUnique2("bigger string")}`);
console.log(`Checking 'dub spc ': ${checkUnique2("dub spc ")}`);

// Note: Think about the character set during an interview question
// Space and time complexity are dependent on the character set in this example

// Did not consider:
// - bit vectors
// - sorting string and then comparing