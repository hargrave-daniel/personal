/*
Daniel Hargrave
Feb 24, 2025
Activity06 - Variables
*/

//I am commenting out errors after I do the test
console.log("---- I am in V A R I A B L E S ----");

// Q1 : Is it permited the next ?
console.log("Q1 ---------------");
var var1 = "Iowa";
console.log(var1);
var var1 = 124;
console.log(var1);
// Is it permited ?
console.log("Yes");

// Q2 : Is it valid ?
console.log("Q2 ----------------");
let var2 = "Ames";
console.log(var2);
//let var2 = 124;
// Is it valid ?
console.log("No, can't redefine variable with let");

// Q3 : Is it valid ?
console.log("Q3 ----------------");
let var3 = "ISU";
console.log(var3);
var3 = 2023;
console.log(var3);
console.log("It is valid because you didn't use let to change it");


// Q4 : Explain the Error.
console.log("Q4 ----------------");
let var4;
//const var5;
console.log("There is no initialization for constant var5, it must be initialized");

// Q5 : Explain the Error.
console.log("Q5 ----------------");
const var6 = 3.1415;
//var6 = 2.8;
console.log("You can't reassign a const variable");


// Q6 : Explain the Error.
//let first name = "Abraham";
console.log("The variable name cannot have a space, I like to use _");
//let 2numbers = [1, 2];
console.log("The variable name cannot start with a number, it can be elsewhere in the variable name");
//let city-state = "Ames Iowa";
console.log("The variable name cannot have the majority of special characters like - in this case");

// Q7 : What !! ??
let mainCity = "DesMoines";
//console.log("This is the Capital :", MainCity);
console.log("Capitalization matters obviously, just fix it");

// Q8 : "let" and "const" scope vs "var" scope
if (5 === 5) {
    var var7 = 100;
}
console.log(var7);
if (5 === 5) {
    let var8 = 100;
}
//console.log(var8);
console.log("It is unable to recognize what is happening in the if block if you use let.");
