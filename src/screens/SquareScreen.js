import React, { useReducer } from 'react';
import { StyleSheet, Text, View, Button, ActionSheetIOS } from 'react-native';
import ColorCounter from '../components/ColorCounter';

const reducer = (state, howToChangeStateObject) => {
  // state === {red: number, green: number, blue: number};
  //action === {colorToChage: 'red'|| 'green'|| 'blue', amount: 15 || -15}

  switch (howToChangeStateObject.colorToChange) {
    case 'red':
    case 'green':
    case 'blue':
    default:
  }
};
const SquareScreen = () => {
  const [state, dispatch] = useReducer(reducer, { red: 0, green: 0, blue: 0 });
  return (
    <View>
      <ColorCounter onIncrease={() => {}} onDecrease={() => {}} color='Red' />
      <ColorCounter onIncrease={() => {}} onDecrease={() => {}} color='Blue' />
      <ColorCounter onIncrease={() => {}} onDecrease={() => {}} color='Green' />

      <View
        style={{
          height: 100,
          width: 500,
          backgroundColor: `rgb(${red}, ${green}, ${blue})`,
        }}
      ></View>
    </View>
  );
};

export default SquareScreen;

const styles = StyleSheet.create({});
