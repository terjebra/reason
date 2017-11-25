let component = ReasonReact.statelessComponent("TemperatureList");

type temperature = {
  room: string,
  temperature: string,
  id: string,
  date: string
};

let se = ReasonReact.stringToElement;

let make = (~temperatures, _) => {
  ...component,
  render: (_) =>
    <div>
      <Title title="Temperature readings" />
      (
        ReasonReact.arrayToElement(
          Array.of_list(
            List.map(
              (temperature) =>
                <ReactToolboxBundled.Card key=temperature.id>
                  <ReactToolboxBundled.CardTitle
                    title=(se(temperature.temperature ++ "\176C  (" ++ temperature.room ++ ")"))
                    subtitle=(se(temperature.date))
                  />
                </ReactToolboxBundled.Card>,
              temperatures
            )
          )
        )
      )
    </div>
};
