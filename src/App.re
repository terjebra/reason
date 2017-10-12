let se = ReasonReact.stringToElement;

type state = {temperatures: list TemperatureList.temperature};

type action =
  | AddTemperature TemperatureList.temperature;

let component = ReasonReact.reducerComponent "App";

let addZero s :string => String.length s == 1 ? "0" ^ s : s;

let getDate =
  addZero (string_of_int (int_of_float (Js.Date.getDate (Js.Date.make ()))))
  ^ "."
  ^ addZero (string_of_int (int_of_float (Js.Date.getMonth (Js.Date.make ()))))
  ^ "."
  ^ string_of_int (int_of_float (Js.Date.getFullYear (Js.Date.make ())))
  ^ " "
  ^ addZero (string_of_int (int_of_float (Js.Date.getHours (Js.Date.make ()))))
  ^ ":"
  ^ addZero (string_of_int (int_of_float (Js.Date.getMinutes (Js.Date.make ()))))
  ^ ":"
  ^ addZero (string_of_int (int_of_float (Js.Date.getSeconds (Js.Date.make ()))));

let onAdd (form: Form.formState) =>
  AddTemperature {
    id: string_of_float (Js.Date.now ()),
    room: form.room,
    temperature: form.temperature,
    date: getDate
  };

let make _ => {
  ...component,
  initialState: fun () => {temperatures: []},
  reducer: fun action {temperatures} =>
    switch action {
    | AddTemperature temperature =>
      ReasonReact.Update {temperatures: [temperature, ...temperatures]}
    },
  render: fun {state, reduce} =>
    <div className="app">
      <ReactToolboxBundled.AppBar title="Temperatures" />
      <Form onAdd=(reduce onAdd) />
      <TemperatureList temperatures=state.temperatures />
    </div>
};
