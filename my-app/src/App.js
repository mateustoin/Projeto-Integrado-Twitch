import React, { useState, useEffect } from 'react';
import { LineChart, Line, CartesianGrid, XAxis, YAxis, Legend, Tooltip } from 'recharts';
import Label from 'recharts/lib/component/Label';

import axios from 'axios';

function App() {
  // Declarar uma nova variável de state, na qual chamaremos de "count"
  const [data, setData] = useState([]);

  /*
  const data = [{ name: 'Page A', uv: 300, pv: 93, amt: 2100 },
  { name: 'Page B', uv: 350, pv: 115, amt: 2000 },
  { name: 'Page C', uv: 400, pv: 115, amt: 2000 },
  { name: 'Page D', uv: 450, pv: 115, amt: 2000 },
  { name: 'Page E', uv: 500, pv: 115, amt: 2000 }];

  <Line type="monotone" dataKey="pv" stroke="#0000FF" activeDot={{ r: 8 }} />
  <Line type="monotone" dataKey="amt" stroke="#FF0000" />
  */
  useEffect(() => {
    axios.get('https://projeto-integrado-bittoin.herokuapp.com/dados/distancia')
      .then(res => {
        const data = res.data;
        console.log(data);
        setData(data);
      })
  });

  return (
    <div className="App">
      <LineChart width={800} height={500} data={data}>
        <Line type="monotone" dataKey="Distancia" stroke="#000000" />
        <CartesianGrid stroke="#ccc" />
        <XAxis dataKey="Timestamp">
          <Label value="Data em que foi registrado" position="insideBottom" />
        </XAxis>
        <YAxis>
          <Label value="Distancia (cm)" angle={-90} position="insideLeft" />
        </YAxis>
        <Tooltip />
        <Legend />

      </LineChart>
    </div>
  );
}

export default App;
