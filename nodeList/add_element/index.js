// NodeList = Static collection of HTML elements by (id, class, element)
//            Can be created by using querySelectorAll()
//            Similar to an array, but no (map, filter, reduce)
//            NodeList won't update to automatically reflect changes

let buttons = document.querySelectorAll(".myButtons");

// ADD AN ELEMENT

const newButton = document.createElement("button"); // STEP 1
newButton.textContent = "Button 5"; // STEP 2
newButton.classList = "myButtons";
document.body.appendChild(newButton); // STEP 3

buttons = document.querySelectorAll(".myButtons");

console.log(buttons)