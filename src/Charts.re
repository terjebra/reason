let component = ReasonReact.statelessComponent "Charts";

let se = ReasonReact.stringToElement;

let make _ => {...component, render: fun _ => <h1> (se "There will be charts!") </h1>};
