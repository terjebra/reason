open MomentRe;

let se = ReasonReact.stringToElement;

type state = {temperatures: list TemperatureList.temperature};

type action =
  | AddTemperature TemperatureList.temperature;

let component = ReasonReact.reducerComponent "Temperatures";

let onAdd (form: Form.formState) =>
  AddTemperature {
    id: string_of_float (Js.Date.now ()),
    room: form.room,
    temperature: form.temperature,
    date: momentNow () |> Moment.format "hh:mm:ss DD.MM.YYYY"
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
    <div> <Form onAdd=(reduce onAdd) /> <TemperatureList temperatures=state.temperatures /> </div>
};
