type routes =
  | TemperaturesRoute
  | ChartsRoute;

let router = DirectorRe.makeRouter({"/": "charts", "/temperatures": "temperatures"});

let temperatures = <Temperatures />;

let charts = <Charts />;

let renderForRoute = (route) => {
  let element =
    switch route {
    | TemperaturesRoute => <Layout page=temperatures />
    | ChartsRoute => <Layout page=charts />
    };
  ReactDOMRe.renderToElementWithId(element, "root")
};

let handlers = {
  "charts": () => renderForRoute(ChartsRoute),
  "temperatures": () => renderForRoute(TemperaturesRoute)
};

DirectorRe.configure(router, {"html5history": true, "resource": handlers});

let path: string = [%bs.raw "window.location.pathname"];

DirectorRe.init(router, path);
