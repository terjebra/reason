const path = require('path')
const webpack = require('webpack')
const ExtractTextPlugin = require("extract-text-webpack-plugin");
const HtmlWebpackPlugin = require("html-webpack-plugin");

const HTML_WEBPACK_OPTIONS = {
  main: {
    title: "Temperatures",
    inject: false,
    template: "./index.ejs",
    appId: "root",
    css: ["style.css"]
  }
};

const plugins = [
  new webpack.DefinePlugin({
    'process.env': {
      NODE_ENV: JSON.stringify('development'),
    },
  }),
  new ExtractTextPlugin({
    filename: "style.css"
  }),
  new HtmlWebpackPlugin(HTML_WEBPACK_OPTIONS.main)
]

const rules = [
    {
      test: /\.css$/,
      use: ExtractTextPlugin.extract({
        fallback: "style-loader",
        use: [
          {
            loader: "css-loader",
            options: {
              modules: true,
              importLoaders: 1,
              localIdentName: "[name]__[local]__[hash:base64:8]"
            }
          },        
            "postcss-loader"
        ]
      })
}];

module.exports = {
  module: {
    rules:rules
  },
  plugins,
  entry: './lib/js/src/main.js',
  output: {
      path: __dirname + '/public',
      filename: "app.js",      
    },
  resolve:{
    alias: {
      src: path.resolve(__dirname, 'src/'),
    }
  },
  devServer: {
    contentBase: "./public",
    historyApiFallback: true,
    port: 3000,
    compress: false,
    inline: true,
    hot: true,
    host: "0.0.0.0",
    stats: {
      assets: true,
      children: false,
      chunks: false,
      hash: false,
      modules: false,
      publicPath: false,
      timings: true,
      version: false,
      warnings: true,
      colors: {
        green: "\u001b[32m"
      }
    }
  }
  }