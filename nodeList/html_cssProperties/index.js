// NodeList = Static collection of HTML elements by (id, class, element)
//            Can be created by using querySelectorAll()
//            Similar to an array, but no (map, filter, reduce)
//            NodeList won't update to automatically reflect changes

let buttons = document.querySelectorAll(".myButtons");

// ADD HTML/CSS PROPERTIES
buttons.forEach(button => {
    button.style.backgroundColor = "green";
    button.textContent += "😂";
});