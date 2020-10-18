import React from 'react';
import { BottomNavigation, BottomNavigationAction } from '@material-ui/core';
import { makeStyles } from '@material-ui/core/styles';

import logo_instagram from './icons/instagram.png';
import logo_twitch from './icons/twitch.png';
import logo_github from './icons/github.png';

/*
    FAZER DOWNLOAD DO REACT-ROUTER-DOM PARA USAR LINK:
    onClick={<Link target="_blank" to='http://www.google.com'>Google</Link>}
*/

function Footer() {
    const useStyles = makeStyles({
        root: {
            width: 500,
        },
    });

    const classes = useStyles();
    const [value, setValue] = React.useState('recents');
    const render_instagram = (
        <img src={logo_instagram} height='45%' width='45%'/>
    );
    const render_twitch = (
        <img src={logo_twitch} height='45%' width='45%'/>
    );
    const render_github = (
        <img src={logo_github} height='45%' width='45%'/>
    );

    return (
        <div className="App">
            <BottomNavigation
                value={value}
                onChange={(event, newValue) => {
                    setValue(newValue);
                }}
                showLabels
                className={classes.root}
            >
                <BottomNavigationAction label="@mateustoin" icon={render_github} />
                <BottomNavigationAction label="@matteus_antonio" icon={render_instagram} />
                <BottomNavigationAction label="@bittoin" icon={render_twitch} />
            </BottomNavigation>
        </div>
    );
}

export default Footer;