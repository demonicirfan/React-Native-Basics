import React, { useReducer } from 'react';
import { StyleSheet, Text, View, Button, ActionSheetIOS } from 'react-native';
import ColorCounter from '../components/ColorCounter';

const reducer = (state, action) => {
  // state === {red: number, green: number, blue: number};
  //action === {type: 'change_red'|| 'change_green'|| 'change_blue', payload: 15 || -15}

  switch (action.type) {
    case 'change_red':
      // not todo: state.red = state.red -20
      return state.red + action.payload > 255 || state.red + action.payload < 0
        ? state
        : { ...state, red: state.red + action.payload }; //returning a new object to be used as state
    case 'change_green':
      return state.green + action.payload > 255 ||
        state.green + action.payload < 0
        ? state
        : { ...state, green: state.green + action.payload };
    case 'change_blue':
      return state.blue + action.payload > 255 ||
        state.blue + action.payload < 0
        ? state
        : { ...state, blue: state.blue + action.payload };
    default:
      return state;
  }
};
const SquareScreen = () => {
  const [state, dispatch] = useReducer(reducer, {
    red: 0,
    green: 0,
    blue: 0,
  }); //run my reducer -> dispatch
  const { red, green, blue } = state;
  return (
    <View>
      <ColorCounter
        onIncrease={() => dispatch({ type: 'change_red', payload: 15 })}
        onDecrease={() => dispatch({ type: 'change_red', payload: -15 })}
        color='Red'
      />
      <ColorCounter
        onIncrease={() => dispatch({ type: 'change_green', payload: 15 })}
        onDecrease={() => dispatch({ type: 'change_green', payload: -15 })}
        color='Green'
      />
      <ColorCounter
        onIncrease={() => reducer({ type: 'change_blue', payload: 15 })}
        onDecrease={() => reducer({ type: 'change_blue', payload: -15 })}
        color='Blue'
      />

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
