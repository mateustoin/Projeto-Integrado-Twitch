import React from 'react';
import { LineChart, Line, CartesianGrid, XAxis, YAxis, Legend, Tooltip } from 'recharts';
import Label from 'recharts/lib/component/Label';

function App() {
  const data = [{ name: 'Page A', uv: 300, pv: 93, amt: 2100 },
  { name: 'Page B', uv: 350, pv: 115, amt: 2000 },
  { name: 'Page C', uv: 400, pv: 115, amt: 2000 },
  { name: 'Page D', uv: 450, pv: 115, amt: 2000 },
  { name: 'Page E', uv: 500, pv: 115, amt: 2000 }];

  return (
    <div className="App">
      <LineChart width={800} height={500} data={data}>
        <Line type="monotone" dataKey="uv" stroke="#000000" />
        <CartesianGrid stroke="#ccc" />
        <XAxis dataKey="name" label="Testando titulo eixo X" />
        <YAxis>
          <Label value="Testando Y" angle="-90" position="insideLeft" />
        </YAxis>
        <Tooltip />
        <Legend />

        <Line type="monotone" dataKey="pv" stroke="#0000FF" activeDot={{ r: 8 }} />
        <Line type="monotone" dataKey="amt" stroke="#FF0000" />
      </LineChart>
    </div>
  );
}

export default App;
