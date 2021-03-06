import React from 'react';
import ReactDOM from 'react-dom';
import './index.css';
import App from './App';
import Header from './Header';
import Footer from './Footer';
import * as serviceWorker from './serviceWorker';

// <App />
/*
function formatName(User){
  return User.firstName + ' ' + User.lastName
}

const User = {
  firstName: 'Mateus',
  lastName: 'Antonio'
}

const element = <h1>Hello, {formatName(User)}</h1>

const element2 = (
  <div>
    <h1>Alo alo rapaziada!</h1>
    <h2>Bem vindo {formatName(User)}</h2>
  </div>
);

function tick() {
  const element = (
    <div>
      <h1>Hello, world!</h1>
      <h2>It is {new Date().toLocaleTimeString()}.</h2>
    </div>
  );
  ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);
*/

class Clock extends React.Component {
  constructor(props){
    super(props);
    this.state = {
      date: new Date()
    };
  }

  componentDidMount(){
    this.timerID = setInterval(
      () => this.tick(), 1000
    );
  }

  componentWillUnmount(){
    clearInterval(this.timerID);
  }

  tick(){
    this.setState({
      date: new Date()
    });
  }

  render() {
    return (
      <div>
        <h1>Hello World galeris!</h1>
        <h2>It is {this.state.date.toLocaleTimeString()}.</h2>
      </div>
    );
  }
}

class Toggle extends React.Component {
  constructor(props) {
    super(props);
    this.state = { isToggleOn: true };

    // Aqui utilizamos o `bind` para que o `this` funcione dentro da nossa callback
    this.handleClick = this.handleClick.bind(this);
  }

  handleClick() {
    this.setState(state => ({
      isToggleOn: !state.isToggleOn
    }));
  }

  render() {
    return (
      <button onClick={this.handleClick}>
        {this.state.isToggleOn ? 'ON' : 'OFF'}
      </button>
    );
  }
}

ReactDOM.render(
  <React.StrictMode>
    <div style={{
        display: 'flex',
        flexDirection: 'column'
      }}>
      <div styl={{
        flex: '1 0 auto',
        padding: '20px'
      }}>
        <Header/>
        <div style={
          {display: 'block',
          marginLeft: 'auto',
          marginRight: 'auto',
          width: '40%',
          paddingTop: '5%'}
        }>
          <App/>
        </div>

      </div>

      <footer style={{
        flexShrink: '0',
        padding: '20px',
        marginTop: '300px',
        display: 'flex',
        flexDirection: 'row',
        justifyContent: 'center'
      }}>
        <Footer/>
      </footer>
    </div>
  </React.StrictMode>,
  document.getElementById('root')
);


// If you want your app to work offline and load faster, you can change
// unregister() to register() below. Note this comes with some pitfalls.
// Learn more about service workers: https://bit.ly/CRA-PWA
serviceWorker.unregister();