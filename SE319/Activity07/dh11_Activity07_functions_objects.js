/*
Daniel Hargrave
Feb 21, 2025
Activity07
*/

function maxOfTwo(n1, n2) {
    if (n1 > n2)
        return n1;
    else
        return n2;
}

function maxOfArray(array) {
    let maxNumber = array[0];
    for (let i in array) {
        if (array[i] > maxNumber) {
            maxNumber = array[i];
        }
    }
    return maxNumber;
}

const movie = {
    title: 'Some movie',
    releaseYear: 2018,
    rating: 4.5,
    director: 'Steven Spielberg'
};

function showProperties(array) {
    let obj = array[0];
    console.log("List of Keys:");
    for (let key in obj) {
        console.log(key);
    }
    console.log("List of Values:");
    for (let key in obj) {
        console.log(obj[key]);
    }
}

const circle = {
    radius: 2,
    area() {
        return Math.PI * this.radius * this.radius;
    }
};

const circle2 = {
    radius: 2,
    area: function () {
        return Math.PI * this.radius * this.radius;
    },
    get radiusValue() {
        return this.radius;
    },
    set radiusValue(value) {
        this.radius = value;
    }
};

const circle3 = {
    radius: 2,
    area: function () {
        return Math.PI * this.radius * this.radius;
    },
    getRadiusValue: function () {
        return this.radius;
    },
    setRadiusValue: function (value) {
        this.radius = value;
    }
};

var var1 = 7;
var var2 = 3;
console.log(maxOfTwo(var1, var2));

let array = [10, 11, 1024, 125, 9, 201];
console.log(maxOfArray(array));

showProperties([movie]);

console.log(circle.area());

console.log(`Area with ${circle2.radiusValue} :`, circle2.area());
circle2.radiusValue = 3;
console.log(`Area with ${circle2.radiusValue} :`, circle2.area());

console.log(`Area with ${circle3.getRadiusValue()} :`, circle3.area());
circle3.setRadiusValue(3);
console.log(`Area with ${circle3.getRadiusValue()} :`, circle3.area());
