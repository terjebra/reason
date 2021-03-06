type formState = {
  room: string,
  temperature: string
};

let se = ReasonReact.stringToElement;

type action =
  | UpdateRoom(string)
  | UpdateTemperature(string)
  | Submit;

let component = ReasonReact.reducerComponent("Form");

let submit = (_event) => Submit;

let make = (~onAdd, _) => {
  ...component,
  initialState: () => {room: "", temperature: ""},
  reducer: (action, formState) =>
    switch action {
    | UpdateRoom(value) => ReasonReact.Update({...formState, room: value})
    | UpdateTemperature(value) => ReasonReact.Update({...formState, temperature: value})
    | Submit =>
      ReasonReact.UpdateWithSideEffects({room: "", temperature: ""}, ((_self) => onAdd(formState)))
    },
  render: ({state, reduce}) =>
    <div>
      <ReactToolboxBundled.Input
        floating=true
        label=(se("Room"))
        onChange=((value, _) => (reduce((value) => UpdateRoom(value)))(value) |> ignore)
        value=state.room
      />
      <ReactToolboxBundled.Input
        floating=true
        label=(se("Temperature"))
        value=state.temperature
        onChange=((value, _) => (reduce((value) => UpdateTemperature(value)))(value) |> ignore)
      />
      <ReactToolboxBundled.Button
        primary=true
        ripple=true
        raised=true
        label="Add"
        onClick=(reduce(submit))
      />
    </div>
};
