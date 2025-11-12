// this = reference to the object where THIS is used
//        (the object depends on the immediate context)      
//        person.name = this.name

const spirit1 = {
    name: "Fainting Warrior",
    place: "Golden Wasteland",
    sayHello: function(){console.log(`Hi! I am the ${this.name}`)},
    realm: function(){console.log(`I am from ${this.place}`)}
}

const spirit2 = {
    name: "Waving Bellmaker",
    place: "Daylight Prairie",
    sayHello: function(){console.log(`Hi! I am the ${this.name}`)},
    realm: function(){console.log(`I am from ${this.place}`)}
}

spirit1.realm();

spirit2.realm();
