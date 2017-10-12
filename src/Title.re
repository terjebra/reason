type styleType = Js.t {. title : string};

let styles: styleType = [%bs.raw "require('src/title.css')"];

let component = ReasonReact.statelessComponent "Title";

let se = ReasonReact.stringToElement;

let make ::title _ => {
  ...component,
  render: fun _ => <h2 className=styles##title> (se title) </h2>
};
