let component = ReasonReact.statelessComponent("Layout");

let make = (~page, _) => {
  ...component,
  render: (_) =>
    <div>
      <ReactToolboxBundled.AppBar title="Temperatures" flat=true>
        <ReactToolboxBundled.Navigation>
          <ReactToolboxBundled.Link href="/temperatures" label="Temperatures" />
          <ReactToolboxBundled.Link href="/" label="Charts" />
        </ReactToolboxBundled.Navigation>
      </ReactToolboxBundled.AppBar>
      page
    </div>
};
