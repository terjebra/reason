const webpack = require("webpack");
const fs = require("fs");
const path = require("path");

const reactToolboxVariables = {
  "font-size-big": "calc(1.8 * var(--unit))",
  "preferred-font": "'Roboto', 'Helvetica', 'Arial', sans-serif",
  "font-size": "calc(1.8 * var(--unit))",
  "font-size-tiny": "calc(1.4 * var(--unit))",
  "font-size-small": "calc(1.6 * var(--unit))",
  "font-size-normal": "var(--font-size)",
  "font-size-big": "calc(2.0 * var(--unit))",
  "font-weight-thin": "300",
  "font-weight-normal": "400",
  "font-weight-semi-bold": "500",
  "font-weight-bold": "700"
};

module.exports = {
  plugins: {
    'postcss-import': {
      root: __dirname,
    },
    'postcss-mixins': {},
    'postcss-each': {},
    'postcss-cssnext': {
      browsers: ["last 2 versions", "ie >= 9"],
      compress: true,
      features: {
        customProperties: {
          variables: reactToolboxVariables
        }
      }
    },
  }
}