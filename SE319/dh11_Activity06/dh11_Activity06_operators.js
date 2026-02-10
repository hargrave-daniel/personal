/*
Daniel Hargrave
Feb 24, 2025
Activity06 - Operators
*/

console.log("---- I am in O P E R A T O R S ----");

console.log("Q1 ---------------");
var var1 = 5 + 9 / 2 + 1;
console.log(var1);
console.log("It follows order of operations");
var var2 = 9 / 2;
console.log(var2);

console.log("Q2 ---------------");
var var3 = 10 / 4;
console.log(var3);
var var4 = 7 % 4;
console.log(var4);
var var2_Answer = var3 + var4;
console.log(var2_Answer);
console.log("% gets remainder");


console.log("Q3 ---------------");
var var5 = (5 - 1) * ((7 + 1) / (3 - 1));
console.log(var5);
console.log("Parenthesis like in order of operations take priority");


console.log("Q4 ---------------");
var var6 = 10 / 4 >= 10 / 3;
console.log(var6);
console.log("It is boolean, true or false");


console.log("Q5 ---------------");
var var7 = 10 >= 10 && 10 <= 10;
console.log(var7);
console.log("It is true because 10 = 10");

// Q6: Strict Equality
// (Type AND Value)

console.log("Q6 ---------------");
console.log(1 === 1);
console.log("True because they are both numbers");
console.log('1' === 1);
console.log("False because they are a number and a string");


console.log("Q7 ---------------");
console.log('1' == 1);
console.log(true == 1);
console.log("Now that we are using == instead of === they are both true because they hold the same value even if they are different types");

