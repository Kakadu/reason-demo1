/* let _ = 
  [%bs.raw {| console.log('here is some фывафываф javascript for you') |}];

ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");

ReactDOMRe.renderToElementWithId(<St1 greeting="Hello!" />, "index3"); */

type ymaps_t;

[@bs.val]
external ymaps : ymaps_t = "ymaps";


module Map = {
    type t;
    /* [@bs.send]
    external ymapsMap : ymaps_t => string => t = "Map"; */
    
    [@bs.deriving abstract]
    type args = {
        center: (float, float),
        zoom: int     
    };

    [@bs.send]
    external ready : ymaps_t => (unit => unit) => unit = "ready";
    

    [@bs.new] [@bs.scope "ymaps"]  external createMap : string => args => t = "Map";
};

let mainMap = ref(None);

let () = Map.ready(ymaps, (() => {
    /* Js.log("maps are ready") */
    Js.log("maps are ready");
    let m = Map.createMap("mapHolder", Map.args(~center=(55.0,37.0), ~zoom=10) );
    mainMap := Some (m);
   })
  );
  
  /* ymaps (fun () -> Map.createMap("mapHolder") ) */
  

/* let ymaps: ymaps_t = [%bs.raw {| ymaps |}]; */
/* let map1 = Map.createMap("mapHolder"); */

/* let map = [%bs.raw {| new ymaps.Map("map", { center: [55.76, 37.64], zoom: 7 }); |}]; */

