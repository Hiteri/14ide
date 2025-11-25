// element selectors = Methods used to target and manipulate HTML elements
//                     They allow you to select one or multiple HTML elements
//                     from the DOM (Document Object Model)

// 1. document.getElementById()           // ELEMENT OR NULL
// 2. document.getElementsClassName()     // HTML COLLECTION
// 3. document.getElementsByTargetName()  // HTML COLLECTION
// 4. document.querySelector()            // ELEMENT OR NULL
// 5. document.querySelectorAll()         // NODELIST

const foods = document.querySelectorAll("li");

foods.forEach(food => {
    food.style.backgroundColor = "yellow";
})